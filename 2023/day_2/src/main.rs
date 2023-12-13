use std::fs::File;
use std::io::prelude::*;
use std::vec;

fn get_input() -> String {
    let mut file = File::open("src/input.txt").expect("Attempted to read file.");
    let mut contents = String::new();

    file.read_to_string(&mut contents).expect("Attempted to read file.").to_string();


    return contents;
}

struct Colour {
    r: i32,
    g: i32,
    b: i32
}

fn main() {

    let mut possible_games: Vec<i32> = vec![];
    let mut possible_games_sum: i32 = 0;

    for line in get_input().lines() {
        
        let mut colours = Colour {
            r: 0,
            g: 0,
            b: 0
        };

        let game_id: i32 = line.split(": ").collect::<Vec<&str>>()[0].split(" ").collect::<Vec<&str>>()[1].parse().expect("Cou");
        let infomation = line.split(": ").collect::<Vec<&str>>()[1];
        let sets = infomation.split("; ").collect::<Vec<&str>>();

        for set in sets {
            let cubes = set.split(", ").collect::<Vec<&str>>();
            
            for cube in cubes {
                let cube_data: (i32, &str) = 
                    (cube.split(" ").collect::<Vec<&str>>()[0].parse().unwrap(), 
                    cube.split(" ").collect::<Vec<&str>>()[1]); 

                match cube_data.1 {
                    "red" => {
                        if cube_data.0 > colours.r {
                            colours.r = cube_data.0
                            }
                        }
                    "green" => {
                        if cube_data.0 > colours.g {
                            colours.g = cube_data.0
                            }
                        }
                    "blue" => {
                        if cube_data.0 > colours.b {
                            colours.b = cube_data.0
                            }
                        }
                    _ => {}
                }

            }

        }
            
        if colours.r <= 12 
        && colours.g <= 13
        && colours.b <= 14 {
            possible_games.push(game_id);
            println!("Game {}: Y, {} {} {} ({} possible games)", game_id, colours.r, colours.g, colours.b, possible_games.len());
        } else {
            println!("Game {}: N, {} {} {} ({} possible games)", game_id, colours.r, colours.g, colours.b, possible_games.len());
        }

    }

    for game in &possible_games {
        possible_games_sum += game;
    }

    println!("The sum of all the possible games is {} ({} games).", possible_games_sum, possible_games.len())

}