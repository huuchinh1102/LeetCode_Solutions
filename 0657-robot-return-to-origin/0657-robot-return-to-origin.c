bool judgeCircle(char* moves) {
    int len = strlen(moves);
    int vertical = 0;
    int horizontal = 0;
    for (int i = 0; i < len; i++) {
        if (moves[i] == 'U') vertical++;
        if (moves[i] == 'D') vertical--;
        if (moves[i] == 'L') horizontal--;
        if (moves[i] == 'R') horizontal++;
    }
    if (vertical == 0 && horizontal == 0) return true;
    else return false;
}