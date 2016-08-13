USE cppfinal;

DROP TABLE IF EXISTS Players;

CREATE TABLE Players
(id INT AUTO_INCREMENT PRIMARY KEY,
firstName NVARCHAR(50) NOT NULL,
lastName NVARCHAR(50) NOT NULL);

INSERT INTO Players(firstName, lastName)
VALUES ('Alex', 'Andriishyn'),
('Alex', 'Friesen'),
('Dan', 'Masci');

SELECT * FROM Players