#include "config.h"
#include "run_threads.h"

int main(int argc, char *argv[]) { 
    struct Config configuration;
    if (argc > 1) { 
        // construct configuration from cmd line arguments
    } else {
        configuration = config_default();
    }
    run_threads(configuration);
}