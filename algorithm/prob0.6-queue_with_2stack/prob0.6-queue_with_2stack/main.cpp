#include "queue_with_stack.h"

void main()
{
	enqueue(1);
	display_queue();
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	display_queue();

	dequeue();
	display_queue();
	dequeue();
	display_queue();
	dequeue();
	display_queue();
	dequeue();
	display_queue();
	dequeue();
	display_queue();
	dequeue();
	display_queue();
}