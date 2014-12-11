//////////////////////////////////////////////////////////////
//
// Batch insert records into tables;
// Table SQL
//
// Author LYB/liuyingboo@gmail.com
//
// create database nvst

//
//create table tsolar(obs_obj bigint, obs_org varchar(50), obs_obj_n float,obs_obj_e float,obs_date bigint, obs_oper varchar(20), azimuth float, altitude float, point char(1),wavelenth float, number varchar(20), seeing int, wind_speed int, obs_band varchar(10), off_band varchar(10), exp_time float,temperature float, weather varchar(10), target varchar(20),event varchar(50), fits_path varchar(128), note varchar(200));

///////////////////////////////////////////////////////////////
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <pthread.h>
#include <sys/time.h>

#define MAX 10
pthread_t thread[2];
pthread_mutex_t mut;

int number = 0;

char tmpstr[100];
char sqlstr[2000];
char times[30];

const char *server    =  "localhost";
const char *user      =  "root";
const char *password  =  "gsdjsj";
const char *database  =  "cyy";
const char *insertSQL =  "insert into tpower(fileid,titleid,chcount,frequency,rates,samprate,datlen,startdatetime,enddatetime,code,channelid,lineid,x,phase1,phase2,multiplier,offset,maxlevel,minlevel)";
//======================================

int fileid                   = 0;
long int titleid             = 0;
long int chcount             = 0;
long int frequency           = 0;

long int rates               = 0;
long int samprate            = 0;
long int datlen              = 16120;
long int startdatetime       = 0;
long int enddatetime         = 0;
long int code                = 0;
long int channelid           = 24;

long int lineid              =0;
const char *x[]              ={"voltage","electricity"};
const char *phase1[]         ={"A","B","C"};
const char *phase2[]         ={"A","B","C"};
long int multiplier          =0;
long int offset              =0;
int maxlevel                 =32768;
int minlevel                 =-32768;

struct thArg {
    const char* uid;
    unsigned int count;
    const std::vector<const char*>& qlist;
    thArg(const unsigned int NR, const char* id, const std::vector<const char*>& ql)
        : count(NR),uid(id), qlist(ql) {}
};

extern "C" void* thFun(void* arg) {

    long int result        = 0;
    thArg * myArg          = (thArg*)arg; // recast the argument to the right type

    int count              = 1;
    char * x_proxy         = NULL;
    char * phase1_proxy    = NULL;
    char * phase2_proxy    = NULL;

    time_t curtime         =  time(NULL);

    double beg_time = getCurrentTimeBySec();

    MYSQL conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    mysql_init(&conn);

    if (!mysql_real_connect(&conn,
                            server,
                            user,
                            password,
                            database,
                            0,
                            NULL,
                            0))
    {
        fprintf(stderr, "%s\n", mysql_error(&conn));
    }

    //close auto commit
    mysql_autocommit(&conn,0);

    memset(sqlstr,0,strlen(sqlstr));
    long long presentTime = 0;
    for(int i = 0; i < myArg->count; i++)
    {
        strcat(sqlstr,insertSQL);

        fileid              = (randomData(200)+10)/10;
        titleid             = (randomData(1000)+10)/10;
        chcount             = (randomData(20)+10)/10;
        frequency           = (randomData(3000)+10)/10;
        
        rates               = (randomData(100)+10)/10;
        samprate            = (randomData(100)+10)/10;
        datlen              = 16120;
        startdatetime       = curtime; 
        enddatetime         = curtime + (randomData(100000)+10)/10;
        code                = (randomData(2000)+10)/10;
        channelid           = 24;
        
        lineid              =(randomData(100)+10)/10;
        multiplier          =(randomData(4000)+10)/10;
        offset              =(randomData(300)+10)/10;

        x_proxy             = const_cast<char*>(x[(int)randomData(2)]);
        phase1_proxy        = const_cast<char*>(phase1[(int)randomData(3)]);
        phase2_proxy        = const_cast<char*>(phase2[(int)randomData(3)]);

       strcat(sqlstr,"VALUES(");
//# 1
        sprintf(tmpstr,"%d",fileid);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//# 2        
        sprintf(tmpstr,"%ld",titleid);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//# 3        
        sprintf(tmpstr,"%ld",chcount);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//# 4        
        sprintf(tmpstr,"%ld",frequency);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//# 5        
        sprintf(tmpstr,"%ld",rates);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//# 6        
        sprintf(tmpstr,"%ld",samprate);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//# 7        
        sprintf(tmpstr,"%ld",datlen);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//# 8        
        sprintf(tmpstr,"%ld",startdatetime);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//# 9        
        sprintf(tmpstr,"%ld",startdatetime+30);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//#10        
        sprintf(tmpstr,"%ld",code);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//#11        
        sprintf(tmpstr,"%ld",channelid);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//#13        
        sprintf(tmpstr,"%ld",lineid);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//#14        
        sprintf(tmpstr,"'%s'",x_proxy);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//#15        
        sprintf(tmpstr,"'%s'",phase1_proxy);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//#16        
        sprintf(tmpstr,"'%s'",phase2_proxy);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//#17        
        sprintf(tmpstr,"%ld",multiplier);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//#18        
        sprintf(tmpstr,"%ld",offset);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//19        
        sprintf(tmpstr,"%d",maxlevel);
        strcat(sqlstr,tmpstr);
        strcat(sqlstr,",");
        memset(tmpstr,0,strlen(tmpstr));
//20        
        sprintf(tmpstr,"%d",(signed int)minlevel);
        strcat(sqlstr,tmpstr);
        memset(tmpstr,0,strlen(tmpstr));

        strcat(sqlstr,");");

        printf("\n%s\n",sqlstr);

        mysql_query(&conn,sqlstr);
        if(count%100000 == 0)//commit
        {
            result = mysql_commit(&conn);
            printf("Alread Insert Records:%u \n",count);
            if(result == 0)
            {
                fprintf(stderr, "%s\n", mysql_error(&conn));
            }
        }

        memset(sqlstr,0,strlen(sqlstr));
        memset(tmpstr,0,strlen(tmpstr));

        count++;
        presentTime++;

    }
    result = mysql_commit(&conn);
    double end_time = getCurrentTimeBySec();
    if(!result)
    {
        printf("\nInserted %u rows",count-1);
    }
    else
    {
        fprintf(stderr, "%s\n", mysql_error(&conn));
    }
    mysql_close(&conn);
    double elapsedTime =end_time-beg_time;
    printf("Time elapsed %.5f\n \n",elapsedTime);
    return 0;
}

// printout the usage string
static void usage(const char* name) {
    std::cout << "usage:\n" << name << " [-n|N number of Record to write] "
              << std::endl;
} // usage


int main(int argc, char *argv[])
{

    unsigned int NR=0;
    for (int i=1; i<argc; ++i) {
        if (*argv[i] == '-') {
            switch (argv[i][1]) {
                case 'h':
                case 'H':
                    usage(*argv);
                    exit(0);
                case 'n':
                case 'N':
                    if (i+1 < argc && argv[i+1][0] != '-') {
                        ++ i;
                        NR = atoi(argv[i]);
                    }
                    break;
                case 'd':
                case 'D':

                    break;
                default:
                    usage(*argv);
                    exit(0);
            }
        }
        else { // assume to be a set of query conditioins
            usage(*argv);
            exit(0);
        }

    }
    if( NR == 0)
    {
        std::cout<< "Can not insert zero records into Database!"<< std::endl;
    }
    const char* uid = "LIUYINGBO-INDEX";
    const int nth = 1;

    std::vector<const char*> qlist;
    thArg args(NR, uid, qlist);

    std::vector<pthread_t> tid(nth);
    for (int i = 0; i < nth; ++ i)
    { //
        int ierr = pthread_create(&(tid[i]), 0, thFun, (void*)&args);
        if (ierr != 0)
        {
        }
    }
    for (int i = 0; i < nth; ++ i)
    { //
        pthread_join(tid[i],NULL);
    }

    return 0;
}
