/** The IMDB dataset contains

tconst - Title identifier
titletype - tvSeries, movies, etc.
primaryTitle - Main title
startYear - self explanitory
genres - csv list of all shows


*/

SELECT * FROM shows3 LIMIT 10;



SELECT * FROM shows3 LIMIT 100;

SELECT COUNT(*) FROM shows3;

SELECT COUNT(*) FROM shows WHERE startYear = 2019;

SELECT * FROM shows WHERE primaryTitle = "The Office";

SELECT * FROM shows WHERE genres LIKE "%Comedy%" AND startYear = 2019;

