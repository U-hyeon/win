#include "queue_with_stack.h"

void main()
{
	enqueue(1);
	display_queue();
	enqueue(2);
	display_queue();
	enqueue(3);
	display_queue();
	enqueue(4);
	display_queue();
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
}