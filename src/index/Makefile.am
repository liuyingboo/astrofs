
include $(top_srcdir)/flymake.mk

AUTOMAKE_OPTIONS	=	foreign

#bin_PROGRAMS		=	readFits rtWriteFits offlineIndex  onlineIndex genMassDataToMysql test massdatapq
bin_PROGRAMS		=	genMassDataToMysql 

# readFits_LDADD		=	-lCCfits -lfastbit
# readFits_SOURCES	= 	readFits.cpp

# offlineIndex_LDADD		=	-lCCfits -lfastbit
# offlineIndex_SOURCES	= 	offlineIndex.cpp utils.cpp coreImpl.cpp

# rtWriteFits_LDADD	=	-lCCfits -lfastbit
# rtWriteFits_SOURCES	= 	coreImpl.cpp utils.cpp rtWrite.cpp

# onlineIndex_LDADD	=	-lCCfits -lfastbit
# onlineIndex_SOURCES	=  coreImpl.cpp utils.cpp onlineIndex.cpp

genMassDataToMysql_LDADD	=-L /usr/lib64/mysql -lmysqlclient
genMassDataToMysql_SOURCES	=utils.cpp   massdatamysql.cpp

#test_SOURCES	=  utils.cpp test.cpp

#massdatapq_LDADD	=-L/usr/local/pgsql/lib -lpq 
#massdatapq_SOURCES	=utils.cpp   massdatapq.cpp
