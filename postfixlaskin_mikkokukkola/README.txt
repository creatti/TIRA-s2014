PostFix-laskin 		Mikko Kukkola 2014

Laskin on tehty ja käännetty Microsoft Visual Studio 2013 ohjelmalla. 
Koko VS projekti on pakattuna samassa kansiossa. Ohjelman voi ajaa suoraan Visual Studiosta, 
tai komentoriviltä hakemalla käännetyn .exe tiedoston. 

Laskimesta on tarjolla kaksi erilaista käyttöliittymää. 
Jos haluaa käyttää laskinta ilman että ohjelma tulostaa kokoajan kehotteita joiden mukaan pitää toimia, 
voidaan ohjelma ajaa suoraan Visual Studiosta tai normaalisti komentoriviltä ilman mitään parametrejä.
Jos taas haluaa ajaa ohjelman kehotteiden kanssa pitää ohjelma ajaa komentoriviltä kirjoittamalla 
.exe -tiedoston nimen perään " -p". Eli tässä tapauksessa "postfixlaskin_mikkokukkola -p". 

Testitapaukset	Kohdissa 1-4 syötteessä välilyönti merkitsee <enter>.
1 p	ensimmäisessä vaiheessa kaikki testit tehty peräjälkeen ohjelmaa sulkematta.
syöte		tuloste
? 8 ? 5 + =	13
? 15 - =	-12
? -10 * =	20
? 8 / =		2,5

2 p	
syöte		tuloste
? 1 ? 2 x - =	1
? 6 ? 3 x / =	0,5

3 p	kolmannessa vaiheessa kaikki testit tehty peräjälkeen ohjelmaa sulkematta.
syöte			tuloste
? 1 ? 2 ? 3 s =		6
? -5 ? 10 ? 1 s =	12

4 p
syöte			tuloste
? 4 ? 6 ? 8 a =		6
? 1.5 ? -8 ? 8 a =	0,5

5 p
syöte	tuloste
8 9+ 	17
6 4x-	-2
5 7 3s	15
7-	Stack has just one entry
9 8%	1
10 4^	10000
9v 	3

Harjoitustyöllä tavoitellaan viittä pistettä.

Mikko Kukkola
mikko.kukkola@eng.tamk.fi
050 4664153

Työaika puolen tunnin tarkkuudella		
		
pvm	työaika (h)	Selitys
27.9.2014	0,5	Yhden pisteen työ tehty
1.10.2014	0,5	kahden pisteen työ tehty
2.10.2014	0,5	kolmen ja neljän pisteen työt tehty
19.10.2014	2	viiden pisteen vaatimuksiin tutustuminen ja + - * /  -laskut toimiviksi.
20.10.2014	0,5	Muutaman bugin korjaaminen
20.10.2014	1	Mainin muuttaminen komentoriviltä ajettavaan muotoon (-p)
26.10.2014	1	README.txt -tiedoston luominen/viimeistely.


Työvaihe - 1. piste
Ideana oli saada kalvoissa olevista koodeista toimiva kokonaisuus kasaan. 
Omia lisäyksiä joutui hieman tekemään sinne tänne. Otin myös käyttöön aimmin kurssilla tehdyn 
Stack -luokan. Tutustuin ohjelman toimintaperiaatteisiin ja loin toiminnallisuudet lopuillekin 
peruslaskutoimituksille.

Työvaihe - 2. piste
Tässä vaiheessa piti luoda toiminta "exchange", eli vaihtaa stackissa kahden päälimmäisen luvun paikat 
keskenään. Päätin käyttää valmiita top/push/pop metodeja tässä ja luoda tämän toiminnallisuuden suoraan 
do_commandin switch -lauseeseen yhdeksi tapaukseksi. Toimii käytännössä samalla tavalla kuin peruslaskut
mutta laskujen sijasta vain vaihdetaan lukujen paikkoja.

Työvaihe - 3. piste
Summa -toiminnon luominen eli lasketaan kaikki stackissa olevat luvut yhteen. Tälle toiminnallisuudelle 
loin oman metodin, "sum". Loin silmukan jossa lasketaan stackissa olevia lukuja niin kauan yhteen 
kunnes stack on tyhjä. Loopin jälkeen sijoitetaan juuri laskettu summa stackiin.

Työvaihe - 4. piste
Keskiarvon laskeminen. Tässä metodissa tehdään täysin samat toimenpiteet kuin ylläolevassa summassa, 
mutta summan laskemisen jälkeen jaetaan summa vielä alkuperäisella stackin koolla. Näin saadaan 
keskiarvo stackissa olleista luvuista ja tämä sijoitetaan stackin päällimmäiseksi.

Työvaihe - 5. piste
Dc -ohjelman kaltainen käyttöliittymä, eli käyttöliittymä jossa ei tulosteta mitään kehoitteita, vaan 
käyttäjä tietään mitä pitää syöttää komentoriville ja ohjelma tulostaa vain vastauksia. Loin uuden 
metodin new_interface jossa pyöritään silmukassa niin kauan kunnes käyttäjä syöttää kirjaimen 'q'(quit).
Käyttäjältä kysytään syöte (lauseke) string muodossa. Lauseketta lähdetään tutkimaan merkki merkiltä 
silmukassa, joka kestään niin kauan kuin lausekkeella on pituutta. Jos tutkittava merkki on luku, niin 
pitää tutkia onko käyttäjä syöttänyt heti perään toisenkin luvun eli onko luku tarkoitettu kaksi tai 
useampi numeroiseksi. Edellisen merkin ollessa numero tutkitaan silmukalla seuraaviakin merkkejä, 
etenemättä kuitenkaan käytännössä lausekkeen tutkimisessa. Jos seuraavakin luku on numero, kasvatetaan 
int tyyppistä muuttujaa. Int tyyppistä muuttujaa käytetään hyväksi kun lasketaan yksittäisistä 
numeroista useampi numeroista lukua, jota käyttäjä on tarkoittanut. Ennen tätä laskua täytyy stringistä 
luetut luvut muuttaa laskettavaan muotoon (double). Kun luku on saatu muodostettua doublena, sijoitetaan 
se stackiin. Jos luettu merkki onkin jokin laskennallisista toimituksista, käydään toiminto 
suorittamassa normaalisti "do_command":ssa. Yhtäsuuruus merkkiä ei tarvitse kirjoittaa, vaan toiminnot 
tapahtuvat enterin painalluksella lausekkeen kirjoituksen jälkeen. Syötä '=' jos haluat tarkistaa mikä 
luku on päälimmäisenä stackissa.
Mainissa mennään käyttämään alkuperäistä käyttöliittymään jos ohjelma on käynnistätty argumentilla -p, 
ilman argumenttia tai jollakin muulla argumentilla käynnistettynä ohjelma toimii uudemmalla 
käyttöliittymällä.

