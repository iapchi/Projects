:- initialization(solve).
findOwner([[_,_,Z1]|T],X,Y,Z):- Z\=Z1, findOwner(T,X,Y,Z).
findOwner([[X,Y,Z]|_],X,Y,Z).
	 

sol([['Genevieve', Y1, Z1], ['Lucia', Y2, Z2], ['Vanessa', Y3, Z3], ['Shawna', Y4, Z4]]):- 
													permutation([Y1,Y2,Y3,Y4],[4,5,6,7]),
													permutation([Z1,Z2,Z3,Z4],['Abbott Hill', 'Manzarita', 'Graffetz', 'Williford']),
													findOwner([['Genevieve', Y1, Z1], ['Lucia', Y2, Z2], ['Vanessa', Y3, Z3], ['Shawna', Y4, Z4]], _, B, 'Manzarita'),
													findOwner([['Genevieve', Y1, Z1], ['Lucia', Y2, Z2], ['Vanessa', Y3, Z3], ['Shawna', Y4, Z4]], _, B1, 'Abbott Hill'),
													findOwner([['Genevieve', Y1, Z1], ['Lucia', Y2, Z2], ['Vanessa', Y3, Z3], ['Shawna', Y4, Z4]], _, B2, 'Graffetz'),
													((B==4,Y2==7);(B==7,Y2==4)),
													Y1 is B1-2,
													Y3 is Y1 + 2,
													B2 > Y4,
													write('Genevieve bought a size '), write(Y1), write(' '), write(Z1), write('.\n'),
													write('Lucia bought a size '), write(Y2), write(' '), write(Z2), write('.\n'),
													write('Vanessa bought a size '), write(Y3), write(' '), write(Z3), write('.\n'),
													write('Shawna bought a size '), write(Y4), write(' '), write(Z4), write('.').

solve:- sol([['Genevieve', Y1, Z1], ['Lucia', Y2, Z2], ['Vanessa', Y3, Z3], ['Shawna', Y4, Z4]]).