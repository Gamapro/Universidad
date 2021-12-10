-- use waifus

SELECT * FROM Characters c 
JOIN Series s ON s.id = c.seriesId 
JOIN Creators as cre ON cre.id = c.creatorId 
WHERE c.id=1

select * from CharactersTags ct
join Characters ch on ch.id = ct.idCharacter 
join Tags tg on tg.id = ct.idTag
where ch.id=1

select * from CharactersTags ct
join Characters ch on ch.id = ct.idCharacter
join Series s on s.id = ch.seriesId 
join Tags tg on tg.id = ct.idTag
WHERE ch.name like '%sakura%' or s.name like '%sakura%' or tg.name like '%sakura%'


select t.name from Tags t
join CharactersTags ct on ct.idTag = t.id
where ct.idCharacter = 1000

select c.id, c.Name as Name, s.name as Serie, c.displayPicture as img 
from Characters c
join Series s on s.id = c.seriesId
where c.name like '%titan%' or s.name like '%titan%'



