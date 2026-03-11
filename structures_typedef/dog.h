#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A dog's basic info
 * @name: Pointer to a character string representing the dog's name
 * @age: The age of the dog, as a float
 * @owner: Pointer to a character string representing the owner's name
 * dog_t - Typedef for struct dog
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
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif
