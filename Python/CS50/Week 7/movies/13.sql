-- List the names of all people who starred in a movie in which Kevin Bacon also starred.
SELECT *
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id
WHERE movies.id IN(
    SELECT movies.id
    FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies on stars.movie_id = movies.id
    WHERE people.name = "Kevin Bacon") 
AND NOT "name" = "Kevin Bacon";
