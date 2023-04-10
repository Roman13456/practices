//
// Created by User on 09.03.2023.
//

#ifndef PRACTICE_1_INPUTCHECK2_H
#define PRACTICE_1_INPUTCHECK2_H

#endif //PRACTICE_1_INPUTCHECK2_H
int intInput2(int *link) {
    int boolean;
    boolean = scanf("%d", link);
    while ((getchar()) != '\n'); // to clear the stream
    if (boolean != 1) {
        return 0;
    } else {
        return 1;
    }
}