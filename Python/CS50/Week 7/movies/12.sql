-- List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.

SELECT movies.title
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id
WHERE people.name = "Johnny Depp" AND movies.id IN(
    SELECT movies.id
    FROM people
    JOIN stars ON people.id = stars.person_id
    JOIN movies on stars.movie_id = movies.id
    WHERE people.name = "Helena Bonham Carter")
GROUP BY movies.id;
