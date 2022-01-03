/*
** EPITECH PROJECT, 2021
** Day06
** File description:
** task06
*/

int value_of_string(char const *s)
{
    int result = 0;
    for (int count = 0; s[count] != '\0'; ++count)
        result += s[count];
    return result;
}

int my_strcmp(char const *s1, char const *s2)
{
    int count1 = value_of_string(s1);
    int count2 = value_of_string(s2);
    if (count1 > count2)
        return (1);
    else if (count1 < count2)
        return (-1);
    else
        return (0);
}
