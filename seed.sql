USE cppfinal;
SET SQL_SAFE_UPDATES = 0;

DROP TABLE IF EXISTS Players;

CREATE TABLE Players
(id INT AUTO_INCREMENT PRIMARY KEY,
firstName NVARCHAR(50) NOT NULL,
lastName NVARCHAR(50) NOT NULL,
dateOfBirth NVARCHAR(10));

INSERT INTO Players(firstName, lastName, dateOfBirth) 
VALUES ('Dan', 'Masci', '07/20/1993'), 
	   ('Alex', 'Friesen', '09/15/1995'), 
       ('Alex', 'Andriishyn', '01/05/1994'), 
       ('Mike', 'Masci', '04/19/1991');

SELECT * FROM Players;