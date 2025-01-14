SELECT I.ANIMAL_ID, I.ANIMAL_TYPE, I.NAME
FROM ANIMAL_INS AS I
JOIN ANIMAL_OUTS AS O
ON I.ANIMAL_ID = O.ANIMAL_ID
WHERE I.SEX_UPON_INTAKE LIKE 'Intact%' AND O.SEX_UPON_OUTCOME IN ('Spayed Female', 'Spayed Male', 'Neutered Male', 'Neutered Female')
ORDER BY I.ANIMAL_ID