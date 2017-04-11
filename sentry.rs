// I decided to make a Rust version of the C++ file

use std::fs::{OpenOptions};
use std::io;
use std::path::Path;

static LOG_FILE: &'static str = "/usr/local/clamXav/share/clamav/freshclam.log";

fn touch(path: &Path) -> io::Result<()> {
  match OpenOptions::new().create(true).write(true).open(path) {
    Ok(_) => Ok(()),
    Err(e) => Err(e),
  }
}

fn main() {
  let quit = false;

  while !quit {
    touch(Path::new(LOG_FILE)).unwrap_or_else(|why| {
      println!("! {:?}", why.kind());
    });
    println!("Touched file {:?}", LOG_FILE);
    std::thread::sleep(std::time::Duration::from_millis(60e3 as u64));
  }
}
