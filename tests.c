#define SDL_MAIN_HANDLED
#include "aiv_unit_test.h"
#include "header.h"
#include <stdio.h>

TEST(clock_adding)
{

    Uint32 last_tick = 1200;
	printf("%i \n",last_tick);
    double rot = 0;
    int timer = 0;
	Uint32 current_tick = 3600;
	printf("%i \n",current_tick);
	printf("%i \n", current_tick - last_tick);
	clock_logic(current_tick, &rot, &timer, &last_tick);
	ASSERT_THAT(rot > 0);
}

int main(int argc, char **argv)
{
	RUN_TEST(clock_adding);

	PRINT_TEST_RESULTS();
	return 0;
}
