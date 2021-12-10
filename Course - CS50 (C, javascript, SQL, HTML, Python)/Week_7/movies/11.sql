-- List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
SELECT title
FROM stars
LEFT JOIN movies ON stars.movie_id = movies.id
LEFT JOIN people ON stars.person_id = people.id
LEFT JOIN ratings ON movies.id = ratings.movie_id
WHERE "name" = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;