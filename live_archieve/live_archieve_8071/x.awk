#!/usr/bin/gawk -f

function myrand( n ) {
    return int( n * rand() );
}

BEGIN{
    N = 10;
    if ( 1 in ARGV )
        N = ARGV[1];

    print N, N;
    for(i=0; i<N; i++)
        Name[i] = rand();

    for(i=0; i< N; i++) {
        j = myrand(N);
        k = myrand(N);
	if ( myrand(2) == 0 ) 
        print Name[j], "is-a", Name[k];
	else
        print Name[j], "has-a", Name[k];
    }

    for(i=0; i< N; i++) {
        j = myrand(N);
        k = myrand(N);
	if ( myrand(2) == 0 ) 
        print Name[j], "is-a", Name[k];
	else
        print Name[j], "has-a", Name[k];
    }
}
