PostFix-laskin 		Mikko Kukkola 2014

Laskin on tehty ja k��nnetty Microsoft Visual Studio 2013 ohjelmalla. 
Koko VS projekti on pakattuna samassa kansiossa. Ohjelman voi ajaa suoraan Visual Studiosta, 
tai komentorivilt� hakemalla k��nnetyn .exe tiedoston. 

Laskimesta on tarjolla kaksi erilaista k�ytt�liittym��. 
Jos haluaa k�ytt�� laskinta ilman ett� ohjelma tulostaa kokoajan kehotteita joiden mukaan pit�� toimia, 
voidaan ohjelma ajaa suoraan Visual Studiosta tai normaalisti komentorivilt� ilman mit��n parametrej�.
Jos taas haluaa ajaa ohjelman kehotteiden kanssa pit�� ohjelma ajaa komentorivilt� kirjoittamalla 
.exe -tiedoston nimen per��n " -p". Eli t�ss� tapauksessa "postfixlaskin_mikkokukkola -p". 

Testitapaukset	Kohdissa 1-4 sy�tteess� v�lily�nti merkitsee <enter>.
1 p	ensimm�isess� vaiheessa kaikki testit tehty per�j�lkeen ohjelmaa sulkematta.
sy�te		tuloste
? 8 ? 5 + =	13
? 15 - =	-12
? -10 * =	20
? 8 / =		2,5

2 p	
sy�te		tuloste
? 1 ? 2 x - =	1
? 6 ? 3 x / =	0,5

3 p	kolmannessa vaiheessa kaikki testit tehty per�j�lkeen ohjelmaa sulkematta.
sy�te			tuloste
? 1 ? 2 ? 3 s =		6
? -5 ? 10 ? 1 s =	12

4 p
sy�te			tuloste
? 4 ? 6 ? 8 a =		6
? 1.5 ? -8 ? 8 a =	0,5

5 p
sy�te	tuloste
8 9+ 	17
6 4x-	-2
5 7 3s	15
7-	Stack has just one entry
9 8%	1
10 4^	10000
9v 	3

Harjoitusty�ll� tavoitellaan viitt� pistett�.

Mikko Kukkola
mikko.kukkola@eng.tamk.fi
050 4664153

Ty�aika puolen tunnin tarkkuudella		
		
pvm	ty�aika (h)	Selitys
27.9.2014	0,5	Yhden pisteen ty� tehty
1.10.2014	0,5	kahden pisteen ty� tehty
2.10.2014	0,5	kolmen ja nelj�n pisteen ty�t tehty
19.10.2014	2	viiden pisteen vaatimuksiin tutustuminen ja + - * /  -laskut toimiviksi.
20.10.2014	0,5	Muutaman bugin korjaaminen
20.10.2014	1	Mainin muuttaminen komentorivilt� ajettavaan muotoon (-p)
26.10.2014	1	README.txt -tiedoston luominen/viimeistely.


Ty�vaihe - 1. piste
Ideana oli saada kalvoissa olevista koodeista toimiva kokonaisuus kasaan. 
Omia lis�yksi� joutui hieman tekem��n sinne t�nne. Otin my�s k�ytt��n aimmin kurssilla tehdyn 
Stack -luokan. Tutustuin ohjelman toimintaperiaatteisiin ja loin toiminnallisuudet lopuillekin 
peruslaskutoimituksille.

Ty�vaihe - 2. piste
T�ss� vaiheessa piti luoda toiminta "exchange", eli vaihtaa stackissa kahden p��limm�isen luvun paikat 
kesken��n. P��tin k�ytt�� valmiita top/push/pop metodeja t�ss� ja luoda t�m�n toiminnallisuuden suoraan 
do_commandin switch -lauseeseen yhdeksi tapaukseksi. Toimii k�yt�nn�ss� samalla tavalla kuin peruslaskut
mutta laskujen sijasta vain vaihdetaan lukujen paikkoja.

Ty�vaihe - 3. piste
Summa -toiminnon luominen eli lasketaan kaikki stackissa olevat luvut yhteen. T�lle toiminnallisuudelle 
loin oman metodin, "sum". Loin silmukan jossa lasketaan stackissa olevia lukuja niin kauan yhteen 
kunnes stack on tyhj�. Loopin j�lkeen sijoitetaan juuri laskettu summa stackiin.

Ty�vaihe - 4. piste
Keskiarvon laskeminen. T�ss� metodissa tehd��n t�ysin samat toimenpiteet kuin yll�olevassa summassa, 
mutta summan laskemisen j�lkeen jaetaan summa viel� alkuper�isella stackin koolla. N�in saadaan 
keskiarvo stackissa olleista luvuista ja t�m� sijoitetaan stackin p��llimm�iseksi.

Ty�vaihe - 5. piste
Dc -ohjelman kaltainen k�ytt�liittym�, eli k�ytt�liittym� jossa ei tulosteta mit��n kehoitteita, vaan 
k�ytt�j� tiet��n mit� pit�� sy�tt�� komentoriville ja ohjelma tulostaa vain vastauksia. Loin uuden 
metodin new_interface jossa py�rit��n silmukassa niin kauan kunnes k�ytt�j� sy�tt�� kirjaimen 'q'(quit).
K�ytt�j�lt� kysyt��n sy�te (lauseke) string muodossa. Lauseketta l�hdet��n tutkimaan merkki merkilt� 
silmukassa, joka kest��n niin kauan kuin lausekkeella on pituutta. Jos tutkittava merkki on luku, niin 
pit�� tutkia onko k�ytt�j� sy�tt�nyt heti per��n toisenkin luvun eli onko luku tarkoitettu kaksi tai 
useampi numeroiseksi. Edellisen merkin ollessa numero tutkitaan silmukalla seuraaviakin merkkej�, 
etenem�tt� kuitenkaan k�yt�nn�ss� lausekkeen tutkimisessa. Jos seuraavakin luku on numero, kasvatetaan 
int tyyppist� muuttujaa. Int tyyppist� muuttujaa k�ytet��n hyv�ksi kun lasketaan yksitt�isist� 
numeroista useampi numeroista lukua, jota k�ytt�j� on tarkoittanut. Ennen t�t� laskua t�ytyy stringist� 
luetut luvut muuttaa laskettavaan muotoon (double). Kun luku on saatu muodostettua doublena, sijoitetaan 
se stackiin. Jos luettu merkki onkin jokin laskennallisista toimituksista, k�yd��n toiminto 
suorittamassa normaalisti "do_command":ssa. Yht�suuruus merkki� ei tarvitse kirjoittaa, vaan toiminnot 
tapahtuvat enterin painalluksella lausekkeen kirjoituksen j�lkeen. Sy�t� '=' jos haluat tarkistaa mik� 
luku on p��limm�isen� stackissa.
Mainissa menn��n k�ytt�m��n alkuper�ist� k�ytt�liittym��n jos ohjelma on k�ynnist�tty argumentilla -p, 
ilman argumenttia tai jollakin muulla argumentilla k�ynnistettyn� ohjelma toimii uudemmalla 
k�ytt�liittym�ll�.

