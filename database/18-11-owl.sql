-- MySQL dump 10.16  Distrib 10.1.26-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: 127.0.0.1    Database: owl
-- ------------------------------------------------------
-- Server version	10.1.26-MariaDB-0+deb9u1

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
-- Table structure for table `comodo`
--

DROP TABLE IF EXISTS `comodo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `comodo` (
  `idComodo` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(45) NOT NULL,
  `tipo` tinyint(2) NOT NULL,
  `externo` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`idComodo`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `comodo`
--

LOCK TABLES `comodo` WRITE;
/*!40000 ALTER TABLE `comodo` DISABLE KEYS */;
INSERT INTO `comodo` VALUES (1,'QUARTO MISSURA',1,0),(2,'COZINHA MISSURA',2,0),(3,'Comodo Teste',1,1),(4,'Comodo Teste',1,1),(5,'Comodo Teste',1,1),(6,'Comodo Teste',1,1),(7,'Comodo Teste',1,1),(8,'Comodo Teste',1,1),(9,'Comodo Teste',1,1),(10,'Comodo Teste',1,1),(11,'Comodo Teste',1,1),(12,'Comodo Teste',1,1),(13,'Comodo Teste',1,1),(14,'Comodo Teste',1,1),(16,'Comodo Teste',1,1),(17,'Comodo Teste',1,1),(18,'Comodo Teste',1,1),(19,'Comodo Teste',1,1);
/*!40000 ALTER TABLE `comodo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ocorrencias`
--

DROP TABLE IF EXISTS `ocorrencias`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ocorrencias` (
  `idOcorrencia` int(11) NOT NULL,
  `sensor` varchar(45) NOT NULL,
  `comodo` varchar(45) NOT NULL,
  `dataHora` varchar(45) NOT NULL,
  `observacao` varchar(45) NOT NULL,
  PRIMARY KEY (`idOcorrencia`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ocorrencias`
--

LOCK TABLES `ocorrencias` WRITE;
/*!40000 ALTER TABLE `ocorrencias` DISABLE KEYS */;
INSERT INTO `ocorrencias` VALUES (1,'Luz','Sala','2018-11-18 17:36:00','Ligou');
/*!40000 ALTER TABLE `ocorrencias` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sensor`
--

DROP TABLE IF EXISTS `sensor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sensor` (
  `idSensor` int(11) NOT NULL,
  `nomeSensor` varchar(45) NOT NULL,
  `codigoEquipamento` int(5) NOT NULL,
  `tipo` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`idSensor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sensor`
--

LOCK TABLES `sensor` WRITE;
/*!40000 ALTER TABLE `sensor` DISABLE KEYS */;
INSERT INTO `sensor` VALUES (1,'TESTE',43255,1);
/*!40000 ALTER TABLE `sensor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `usuario`
--

DROP TABLE IF EXISTS `usuario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `usuario` (
  `idUsuario` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(45) NOT NULL,
  `senha` varchar(45) NOT NULL,
  `perfil` enum('Dono','Usuário','Visitante') NOT NULL,
  `nome` varchar(45) NOT NULL,
  `cpf` varchar(45) DEFAULT NULL,
  `rg` varchar(45) DEFAULT NULL,
  `dataNascimento` varchar(45) DEFAULT NULL,
  `email` varchar(45) NOT NULL,
  PRIMARY KEY (`idUsuario`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `usuario`
--

LOCK TABLES `usuario` WRITE;
/*!40000 ALTER TABLE `usuario` DISABLE KEYS */;
INSERT INTO `usuario` VALUES (1,'guibperes@gmail.com','1234','Dono','Guilherme Peres','','','','guibperes@gmail.com'),(2,'dougmissura@gmail.com','81dc9bdb52d04dc20036dbd8313ed055','Usuário','Douglas Missura','','','','dougmissura@gmail.com'),(13,'lleitecs@gmail.com','1234','Visitante','Lucas Leite','','','','lleitecs@gmail.com'),(14,'guibperes@gmail.com','1234','','Guilherme Beidaki','','','','guibperes@gmail.com'),(15,'guibperes@gmail.com','1234','','Guilherme Beidaki','','','','guibperes@gmail.com');
/*!40000 ALTER TABLE `usuario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `usuarioComodo`
--

DROP TABLE IF EXISTS `usuarioComodo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `usuarioComodo` (
  `idUsuarioComodo` int(11) NOT NULL AUTO_INCREMENT,
  `idUsuario` int(11) NOT NULL,
  `idComodo` int(11) NOT NULL,
  PRIMARY KEY (`idUsuarioComodo`),
  UNIQUE KEY `USUARIO_COMODO_UNIQUE` (`idUsuario`,`idComodo`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `usuarioComodo`
--

LOCK TABLES `usuarioComodo` WRITE;
/*!40000 ALTER TABLE `usuarioComodo` DISABLE KEYS */;
INSERT INTO `usuarioComodo` VALUES (2,0,0),(1,2,1);
/*!40000 ALTER TABLE `usuarioComodo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `usuarioSensor`
--

DROP TABLE IF EXISTS `usuarioSensor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `usuarioSensor` (
  `idUsuarioSensor` int(11) NOT NULL AUTO_INCREMENT,
  `idUsuario` int(11) NOT NULL,
  `idSensor` int(11) NOT NULL,
  PRIMARY KEY (`idUsuarioSensor`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `usuarioSensor`
--

LOCK TABLES `usuarioSensor` WRITE;
/*!40000 ALTER TABLE `usuarioSensor` DISABLE KEYS */;
INSERT INTO `usuarioSensor` VALUES (1,2,2);
/*!40000 ALTER TABLE `usuarioSensor` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-11-18 18:32:37
