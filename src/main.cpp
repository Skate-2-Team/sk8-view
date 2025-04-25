#include "Sk8view.h"

int main(int p_argc, char *p_argv[])
{
    Sk8ViewApp app;

    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
