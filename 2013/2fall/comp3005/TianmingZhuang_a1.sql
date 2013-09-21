--SQL Fake Book Song Data


--CREATE DATABASE TABLES
--=======================

create table if not exists songs(
      id integer primary key not null, --auto increment key 
      songTitle text NOT NULL, --title of the songs
      bookCode text NOT NULL,  --book code for the the fake book the song is from
      page int, --page number in book where song appears
      student_number text NOT NULL  --student who contributed the data
      );

--INSERT DATA
--=======================

begin transaction;

--Insert songs
insert into songs(songTitle, bookCode, page, student_number) values 
('Mame', 'SPC4', 208, '100875151'),
('Man From Harlet', 'SPC4', 246, '100875151'),
('Matt''s Blues', 'SPC4', 127, '100875151'),
('Meeting of the Spirits (McLaughlin)', 'SPC4', 232, '100875151'),
('Melvin on Main Street', 'SPC4', 123, '100875151'),
('Michelle (Lenno,McCarnet)', 'SPC4', 40, '100875151'),
('Midnight Sun Will Never Set', 'SPC4', 135, '100875151'),
('MIdwestern Night''s Dream (F.Methany)', 'SPC4', 197, '100875151'),
('Mobile (B.Shank)', 'SPC4', 117, '100875151'),
('Molten Glass (J.Farrell)', 'SPC4', 39, '100875151'),
('Mona Lisa', 'SPC4', 95, '100875151'),
('Montage (S.Balcomb)', 'SPC4', 42, '100875151'),
('Muttnick', 'SPC4', 116, '100875151'),
('My Baby Upsets Me (J.Williams)', 'SPC4', 137, '100875151'),
('My Cherie Amour', 'SPC4', 190, '100875151'),
('My One & Only Love (Wood/Mellin)', 'SPC4', 41, '100875151'),
('My Romance (Rodgers&Hart)', 'SPC4', 43, '100875151'),
('My Ship (Weill/Gershwin)', 'SPC4', 44, '100875151'),
('My Sweet Lord (G.Harrison)', 'SPC4', 217, '100875151'),
('Nancy', 'SPC4', 188, '100875151'),
('Never Can Say Goddbye(Jackson5)', 'SPC4', 174, '100875151'),
('Never Never Land', 'SPC4', 186, '100875151'),
('Never Will I Marry(F.Loesser)', 'SPC4', 45, '100875151'),
('Night & Day (C.Porter)', 'SPC4', 46, '100875151'),
('Night Has a Thousand Eyes (Weisman/Garrett/Wayne)', 'SPC4', 48, '100875151'),
('Nimbus (R.McClure)', 'SPC4', 47, '100875151'),
('No Lover (C.Porter)', 'SPC4', 230, '100875151'),
('Nostalgia', 'SPC4', 146, '100875151'),
('Now He Sings, Now He Sobs (C.Corea)', 'SPC4', 234, '100875151'),
('Olilugal Valley (H.Hancock)', 'SPC4', 150, '100875151'),
('On a Slow Boat to China', 'SPC4', 91, '100875151'),
('On Broadway', 'SPC4', 218, '100875151'),
('Once in a While', 'SPC4', 215, '100875151'),
('One Less Bell to Answer (Bacharack)', 'SPC4', 202, '100875151'),
('On the Alamo (T.Jones)', 'SPC4', 90, '100875151'),
('Out of Nowhere (Green/Heyman)', 'SPC4', 49, '100875151'),
('Pensativa (C.Fischer)', 'SPC4', 50, '100875151'),
('People', 'SPC4', 225, '100875151'),
('Portrait of Tracy (J.Partorius)', 'SPC4', 236, '100875151'),
('Pretend', 'SPC4', 96, '100875151'),
('Princess', 'SPC4', 220, '100875151'),
('Promises, Promises', 'SPC4', 172, '100875151'),
('Quick Step(G.Gryce)', 'SPC4', 128, '100875151'),
('Quiet Now (D.Zeitlin)', 'SPC4', 52, '100875151');

end transaction;
