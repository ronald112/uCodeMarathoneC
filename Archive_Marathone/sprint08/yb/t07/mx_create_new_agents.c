#include "create_new_agents.h"

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count) {
	t_agent **new_agents = (t_agent **)malloc((count + 1) * sizeof(t_agent *));
	int index = 0;

	if (!new_agents) {
		return NULL;
	}
	for (; index < count; index++ ) {
		new_agents[index] = mx_create_agent(name[index], power[index], strength[index]);
	}
	new_agents[index] = NULL;

	return new_agents;
}