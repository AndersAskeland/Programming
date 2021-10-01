-- List the names of all people who have directed a movie that received a rating of at least 9.0.
SELECT "name"
FROM directors
LEFT JOIN movies ON directors.movie_id = movies.id
LEFT JOIN people ON directors.person_id = people.id
LEFT JOIN ratings ON movies.id = ratings.movie_id
WHERE rating >= 9
GROUP BY people.id;