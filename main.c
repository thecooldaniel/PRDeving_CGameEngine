#include <stdio.h>
#include "statemanager.h"

unsigned int initState1(State *foo) {
    printf("state 1 created\n");
    foo->update = NULL;
    return 0;
}

unsigned int destroyState1() {
    printf("state 1 destroyed\n");
    return 0;
}

unsigned int initState2() {
    printf("state 2 created\n");
    return 0;
}

unsigned int updateState2(float deltatime) {
    printf("state 2 update %f\n", deltatime);
    return 0;
}

unsigned int destroyState2() {
    printf("state 2 destroyed\n");
    return 0;
}

int main() {
    StateManager statemanager;
    STATEMANAGER_init(&statemanager);

    State state1;
    state1.init = initState1(&state1);
    state1.destroy = destroyState1;

    State state2;
    state2.init = initState2;
    state2.update = updateState2;
    state2.destroy = destroyState2;

    printf(NULL);
    printf("%i\n", statemanager.stack[0]->update);
    printf("%i\n", statemanager.stack[1]->update);

    STATEMANAGER_push(&statemanager, &state1);
    STATEMANAGER_update(&statemanager, 10.0f);

    STATEMANAGER_push(&statemanager, &state2);
    STATEMANAGER_update(&statemanager, 10.0f);

    STATEMANAGER_pop(&statemanager);
    //STATEMANAGER_update(&statemanager, 10.0f);

    STATEMANAGER_free(&statemanager);
}