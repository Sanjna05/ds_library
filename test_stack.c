#include <stdio.h>
#include "..//src/stack.c"  // Include stack.c from src folder

int main() {
    // Create a stack
    Stack* stack = createStack(5);

    // Test push
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Traverse stack
    traverseStack(stack);

    // Test peek
    printf("Top element: %d\n", peek(stack));

    // Test pop
    printf("Popped: %d\n", pop(stack));
    traverseStack(stack);

    // Test isEmptyStack and isFullStack
    printf("Is empty? %d\n", isEmptyStack(stack));
    printf("Is full? %d\n", isFullStack(stack));

    // Test postfix evaluation
    char expr[] = "23*5+";
    printf("Postfix '%s' result: %d\n", expr, evaluatePostfix(expr));

    // Free stack
    freeStack(stack);

    return 0;
}
