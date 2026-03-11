#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A dog's basic info
 * @name: Pointer to a character string representing the dog's name
 * @age: The age of the dog, as a float
 * @owner: Pointer to a character string representing the owner's name
 *
 * Description: This structure defines the essential attributes of a dog
 * within our veterinary database system. It stores the dog's identity,
 * its age, and its owner's identity.
 */


struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif
