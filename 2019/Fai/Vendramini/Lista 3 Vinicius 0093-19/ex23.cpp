#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
		char mami, quadr, carn, herbi, bip, voa, aqua, oni, ave, repi, nvoa, tropi, nada, casco;
	
	cout<<"o seu animal e um mamifero? \nsim (s) ou nao (n): ";
	cin>>mami;
	
	
	if ( mami == 's' || mami == 's' ) {
		
		cout<<"o seu animal e quadrupide ? \nsim (s) ou nao (n): ";
		cin>>quadr;
		
		if ( quadr == 's' || quadr == 's' ) {
		
			cout<<"o seu animal e carnivoro ? \nsim (s) ou nao (n): ";
			cin>>carn;
				
			if ( carn == 's' || carn == 's' ) {
		
				cout<<"o animal escolhido foi um leao";
			
			}else{
				cout<<"animal escolhido foi um cavalo";
			}
			
		}else if (quadr == 'n' || quadr == 'n'){
			
			cout<<"o seu animal e bipede ? \nsim (s) ou nao (n): ";
			cin>>bip;
			
			if ( bip == 's' || bip == 's' ) {
				
				cout<<"o seu animal e onivoro ? \nsim (s) ou nao (n): ";
				cin>>oni;
				
				if ( oni == 's' || oni == 's' ){
					cout<<"o animal escolhido foi um homem";
				}else{
					cout<<"o animal escolhido foi um macaco";
				}	
			
			}else if( bip == 'n' || bip == 'n' ){
				
				cout<<"o seu animal e voador ? \nsim (s) ou nao (n): ";
				cin>>voa;
				
				if ( voa == 's' || voa == 's' ){
					cout<<"animal escolhido foi um morcego";
				}else{
					cout<<"animal escolhido foi um baleia";
				}
			}
		}
	}else if ( mami == 'n' || mami == 'n' ) {
		
		cout<<"o seu animal e uma ave ? \nsim (s) ou nao (n): ";
		cin>>ave;
		
		if ( ave == 's' || ave == 's' ) {
		
			cout<<"o seu animal e um nao-voador ? \nsim (s) ou nao (n): ";
			cin>>nvoa;
				
			if ( nvoa == 's' || nvoa == 's' ) {
				
				cout<<"o seu animal e tropical ? \nsim (s) ou nao (n): ";
				cin>>tropi;
				
				if ( tropi == 's' || tropi == 's' ){
					cout<<"animal escolhido foi um avestruz";
				}else{
					cout<<"o animal escolhido foi um pinguin";
				}
			
			}else if ( nvoa == 'n' || nvoa == 'n' ) {

				cout<<"o seu animal é um nadador ? \nsim (s) ou nao (n): ";
				cin>>nada;
				
				if ( nada == 's' || nada == 's' ){
					cout<<"animal escolhido foi um pato";
				}else{
					cout<<"animal escolhido foi uma aguia";
				}
			} 
		}else{

			cout<<"o seu animal tem casco ? \nsim (s) ou nao (n): ";
			cin>>casco;
			
			if ( casco == 's' || casco == 's' ){
				cout<<"o animal escolhido foi um tartaruga";

			}else if (casco == 'n' || casco == 'n' ){
				
				cout<<"o seu animal é carnivoro ? \nsim (s) ou nao (n): ";
				cin>>carn;

				if ( carn == 's' || carn == 's' ){
					cout<<"o animal escolhido foi um crocodilo	";
				}else{
					cout<<"o animal escolhido foi um cobra";
				}
			}               
		}
	}

                    
	return 0;
}











