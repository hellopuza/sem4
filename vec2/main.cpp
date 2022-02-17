#include "vec2.h"
#include <iostream>

int main()
{
    vec2 a(1.0F, 2.0F);
    vec2 b(-1.0F, 1.0F);
    vec2 c;

    c = a + b;
    std::cout << c.x << " " << c.y << "\n";

    c = a - b;
    std::cout << c.x << " " << c.y << "\n";

    c = a * b;
    std::cout << c.x << " " << c.y << "\n";

    c = a / b;
    std::cout << c.x << " " << c.y << "\n";

    std::cout << dot(a, b) << "\n";

    return 0;
}