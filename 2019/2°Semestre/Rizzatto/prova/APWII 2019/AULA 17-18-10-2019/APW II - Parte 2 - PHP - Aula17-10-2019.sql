-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: 18-Out-2019 às 00:05
-- Versão do servidor: 5.7.24
-- versão do PHP: 7.1.24

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `loja`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `clientes`
--

CREATE TABLE `clientes` (
  `codigoCli` int(11) NOT NULL,
  `RGCli` varchar(12) DEFAULT NULL,
  `CPFCli` varchar(14) DEFAULT NULL,
  `nomeCli` varchar(70) DEFAULT NULL,
  `enderecoCli` varchar(60) DEFAULT NULL,
  `bairroCli` varchar(60) DEFAULT NULL,
  `cidadeCli` varchar(60) DEFAULT NULL,
  `ufCli` varchar(2) DEFAULT NULL,
  `generoCli` varchar(1) DEFAULT NULL,
  `dataNascimentoCli` date DEFAULT NULL,
  `rendaCli` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `clientes`
--

INSERT INTO `clientes` (`codigoCli`, `RGCli`, `CPFCli`, `nomeCli`, `enderecoCli`, `bairroCli`, `cidadeCli`, `ufCli`, `generoCli`, `dataNascimentoCli`, `rendaCli`) VALUES
(1, '44.103587-X', '123.456.789-12', 'José da Silva', 'Rua santo Antônio, 256', 'centro', 'Adamantina', 'SP', 'M', '2000-03-20', '4532.38'),
(2, '20.167.521-2', '111.222.333-90', 'Maria Alcantara', 'Av. Internacional, 1002', 'centro', 'Lucélia', 'SP', 'F', '1989-01-31', '6390.00'),
(3, '34.100.500-8', '090.070.070-70', 'Carla Machado', 'Al. 2 de abril, 375', 'Vila Cicma', 'Adamantina', 'SP', 'F', '1993-12-10', '3375.93');

-- --------------------------------------------------------

--
-- Estrutura da tabela `produtos`
--

CREATE TABLE `produtos` (
  `codigoProd` int(11) NOT NULL,
  `descricaoProd` varchar(100) DEFAULT NULL,
  `precoProd` decimal(10,2) DEFAULT NULL,
  `dataValidadeProd` date DEFAULT NULL,
  `estoqueProd` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Extraindo dados da tabela `produtos`
--

INSERT INTO `produtos` (`codigoProd`, `descricaoProd`, `precoProd`, `dataValidadeProd`, `estoqueProd`) VALUES
(1, 'chocalate', '6.50', '2019-12-25', 500),
(2, 'salgadinho', '2.50', '2020-01-07', 300),
(10, 'cerveja', '22.00', '2019-10-21', 349),
(20, 'carvao', '30.45', '2060-02-10', 1476);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `clientes`
--
ALTER TABLE `clientes`
  ADD PRIMARY KEY (`codigoCli`);

--
-- Indexes for table `produtos`
--
ALTER TABLE `produtos`
  ADD PRIMARY KEY (`codigoProd`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
