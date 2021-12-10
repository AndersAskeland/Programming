-- Names of all people who starred in Toy Story
SELECT `name`
FROM stars
LEFT JOIN movies ON stars.movie_id = movies.id
LEFT JOIN people on stars.person_id = people.id
WHERE title = "Toy Story";


