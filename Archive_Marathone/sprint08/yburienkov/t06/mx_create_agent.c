#include "create_agent.h"
#include <stdio.h>

t_agent *mx_create_agent(char *name, int power, int strength) {
	if (!name) return NULL;    
	t_agent *t = malloc(sizeof(struct s_agent));
	(*t).name = mx_strdup(name);
	(*t).power = power;
	(*t).strength = strength;

	return t;
}

int main(void) {
	struct s_agent *agent = mx_create_agent("Smith", 150, 66);

	printf("%s %d %d", agent->name, agent->power, agent->strength);
}
