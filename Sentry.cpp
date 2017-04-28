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
    char buff[20];
    struct tm *sTm;

    time_t now = time(0);
    sTm = gmtime(&now);

    strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);

    touch(LOG_FILE);
    printf("[%s] Log file updated: %s\n", buff, LOG_FILE);
    // Sleep for one hour
    usleep(60 * 60e6);
  }
}
