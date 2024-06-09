#include <iostream>

using namespace std;

// Minimum number of cards required to build a pyramid of height 1
const int MIN_PYRAMID_HEIGHT_CARDS = 2;

// Function to calculate the number of cards needed to build level h of a pyramid
int base(int h)
{
    /**
     * Function to calculate the base of a piramid of height h
     * A base consists of h pyramids of height 1, and h−1 cards on top
     */
    if (h == 1)
        return 0; // If the height is 1, there is no additional "base"

    return h * MIN_PYRAMID_HEIGHT_CARDS + (h - 1);
}

int cards_for_level_h(int h)
{
    /**
     * Recursive function to calculate the total number of cards needed to
     * build a pyramid of height h
     */
    if (h == 1)
        return MIN_PYRAMID_HEIGHT_CARDS;

    // For greater heights, add the cards needed for the previous level and
    // the cards needed for the current level
    return cards_for_level_h(h - 1) + base(h);
}

int n_pyramids(int cards)
{
    /**
     * Function to calculate how many pyramids can be built with a given
     * number of cards (n)
     * todo: refactor this only using loops and the base(h) and not recursion
     */
    int h = 1, pyramids = 0, cards_by_level, cache;

    // While there are enough cards to build at least a basic level of the pyramid
    while (cards >= MIN_PYRAMID_HEIGHT_CARDS)
    {
        // Calculate the cards needed for a pyramid of height h
        cards_by_level = cards_for_level_h(h);

        if (cards_by_level <= cards)
        {
            // If there are enough cards for the pyramid of height h, increase the height
            h++;
            cache = cards_by_level; // Save the number of cards used for this height
            continue;               // Continue to the next level of the pyramid
        }

        // there are not enough cards for the next level, build a pyramid
        // with the current height
        cards -= cache; // Subtract the used cards from the available cards
        pyramids++;     // Increment the count of pyramids built
        h = 1;          // Reset the height to build a new pyramid starting from level 1
    }

    return pyramids;
}

int main()
{
    int t = 0, n_cards;

    scanf("%d", &t); // Read the number of test cases

    while (t--)
    {
        scanf("%d", &n_cards);
        printf("%d\n", n_pyramids(n_cards));
    }

    return 0;
}
