-- MySQL dump 10.13  Distrib 5.1.73, for redhat-linux-gnu (x86_64)
--
-- Host: localhost    Database: cyy
-- ------------------------------------------------------
-- Server version	5.1.73

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `tpower`
--

DROP TABLE IF EXISTS `tpower`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tpower` (
  `fileid` int(11) DEFAULT NULL,
  `titleid` bigint(20) DEFAULT NULL,
  `chcount` bigint(20) DEFAULT NULL,
  `frequency` bigint(20) DEFAULT NULL,
  `rates` bigint(20) DEFAULT NULL,
  `samprate` bigint(20) DEFAULT NULL,
  `datlen` bigint(20) DEFAULT NULL,
  `startdatetime` bigint(20) DEFAULT NULL,
  `enddatetime` bigint(20) DEFAULT NULL,
  `code` bigint(20) DEFAULT NULL,
  `channelid` bigint(20) DEFAULT NULL,
  `lineid` bigint(20) DEFAULT NULL,
  `x` varchar(100) DEFAULT NULL,
  `phase1` varchar(100) DEFAULT NULL,
  `phase2` varchar(100) DEFAULT NULL,
  `multiplier` bigint(20) DEFAULT NULL,
  `offset` bigint(20) DEFAULT NULL,
  `maxlevel` int(11) DEFAULT NULL,
  `minlevel` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-11-28 23:05:59
