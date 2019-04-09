#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string url("https//www.reddit.com/r/nevertellmethebots");
    int a = url.find("bots");
    std::string rep = "bots";
    int b = rep.size();
    int c = url.find("//");


    url.replace(a , b , "odds");
    url.insert (c , ":");

    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crucial component, find out what it is and insert it too!

    std::cout << url << std::endl;

    return 0;
}