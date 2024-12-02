const std = @import("std");

const input = @embedFile("input.txt");

const Pair = struct {left: ?i32, right: ?i32};

pub fn main() !void {
    const alloc = std.heap.c_allocator;

    var current_pair = Pair {.left = null, .right = null};

    var pairs = std.ArrayList(Pair).init(alloc);

    var in_number = false;
    var on_left = true;

    // buffer of chars that gets converted into int
    var num_buffer = std.ArrayList(u8).init(alloc);

    for (input) |c| {
        if (std.ascii.isDigit(c)) {
            in_number = true;
            try num_buffer.append(c);
            continue;
        } 

        if (in_number) {
            in_number = false;

            std.debug.print("trying to make this an number: ", .{});
            for (num_buffer.items) |char| {
                std.debug.print("{c}", .{char});
            }
            std.debug.print("\n", .{});

            const num = try std.fmt.parseInt(i32, num_buffer.items, 10);
            num_buffer.clearAndFree();

            if (on_left) {
                current_pair.left = num;
                on_left = false;
            } else {
                current_pair.right = num; 
                on_left = true;
            }
        }

        if (current_pair.right != null and current_pair.left != null) {
            try pairs.append(current_pair);
            current_pair = Pair {.left = null, .right = null};
        }
    }

    std.debug.print("-------------\n", .{});
    for (pairs.items) |p| {
        std.debug.print("{?d} : {?d}\n", .{p.left, p.right}); 
        break;
    }
}
