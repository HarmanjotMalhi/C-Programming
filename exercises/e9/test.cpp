#include <iostream>
#include <pthread.h>
#include <unistd.h>

void *proccy(void *argument)
{
	while (true)
	{
		std::cout << "\tI'm a thread!" << std::endl;
		usleep(1000000); // We could reduce this
	}
}

int main()
{
	pthread_t ct; // our child thread

	/*Note that there's a lot going on here:
	 *The first parameter is used to grab the handle to the thread.
	 *The second parameter, if included, will be an object to specify special pthread attributes (e.g. joinable or detached)
	 *The third parameter is the function to use as the threaded routine
	 *The fourth parameter is a single argument to pass to the thread, as a void pointer
	 */
	pthread_create(&ct, NULL, &proccy, NULL);
	// PTHREAD_CREATE_JOINABLE();
	pthread_join(ct, NULL);
}
