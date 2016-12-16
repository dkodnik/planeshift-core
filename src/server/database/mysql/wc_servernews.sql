--
-- Table structure for table `wc_servernews`
--

DROP TABLE IF EXISTS `wc_servernews`;
CREATE TABLE `wc_servernews` (
  `id` int(10) NOT NULL auto_increment,
  `news` text ,
  UNIQUE KEY `id` (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

#
# Dumping data for table wc_servernews
#

# The system only expects 1 single entry, using ID 1
INSERT INTO `wc_servernews` VALUES (1, 'Server News');