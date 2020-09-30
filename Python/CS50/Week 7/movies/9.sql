-- List the names of all people who starred in a movie released in 2004, ordered by birth year.

SELECT `name`
FROM stars
LEFT JOIN movies ON stars.movie_id = movies.id
LEFT JOIN people on stars.person_id = people.id
WHERE year = 2004
ORDER BY birth;
