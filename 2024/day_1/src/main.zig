const std = @import("std");

const input = @embedFile("input.txt");

const Pair = struct {left: ?i32, right: ?i32};

pub fn main() !void {
    const alloc = std.heap.page_allocator;

    var pairs = std.ArrayList(Pair).init(alloc);

    var line: i32 = 0;
    var char: i32 = 0;

    var pair = Pair {.left = null, .right = null};

    var last_was_digit = false;
    var num_buffer = std.ArrayList(u8).init(alloc);

    var on_left = true;
    var finished_number = false;

    for (input) |c| {
        if (c == '\n') {
            on_left = true;
            char = 0;
            line += 1;

            try pairs.append(pair);
            std.debug.print(">>>>>>>>>>>>>>\n", .{});
            std.debug.print("{?d} : {?d}\n", .{pair.left, pair.right}); 
            std.debug.print(">>>>>>>>>>>>>>\n", .{});

            pair = Pair {.left = null, .right = null};

            num_buffer.clearAndFree();
        } else {
            char += 1;
        }
        
        if (c == ' ') {
            finished_number = true;
            continue;
        }
        if (finished_number) {
            last_was_digit = false;
            finished_number = false;

            std.debug.print("num_buffer: ", .{});
            for (num_buffer.items) |n| {
                std.debug.print("{c}", .{n});
            }
            std.debug.print("\n", .{});

            const num = try std.fmt.parseInt(i32, num_buffer.items, 10);

            if (on_left) {
                pair.left = num;
                on_left = false;
            } else {
                pair.right = num; 
            }
            num_buffer.clearAndFree();
        }

        if (std.ascii.isDigit(c)) {
            last_was_digit = true;
            finished_number = false;
            try num_buffer.append(c);
        } 
        std.debug.print("looked at '{c}' ({s})\n", .{c, if (on_left) "left" else "right"});

    }

    std.debug.print("-------------\n", .{});
    for (pairs.items) |p| {
        std.debug.print("{?d} : {?d}\n", .{p.left, p.right}); 
        break;
    }

    // for (left.items) |n| {
    //     std.debug.print("L: {d}\n", .{n});
    // }
    // for (right.items) |n| {
    //     std.debug.print("R: {d}\n", .{n});
    // }
}
