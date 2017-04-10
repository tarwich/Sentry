#include <fstream>
#include <functional>
#include <map>
#include <unistd.h>

const char* LOG_FILE = "/usr/local/clamXav/share/clamav/freshclam.log";

void touch(const char *file) {
  std::ofstream(std::string(file));
}

int main(int argc, char** argv) {
  while (true) {
    touch(LOG_FILE);
    printf("Log file updated: %s\n", LOG_FILE);
    usleep(60e6);
  }
}
