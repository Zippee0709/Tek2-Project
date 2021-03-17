/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** main
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

int main(void)
{
    // Federation :: Starfleet :: Ship UssKreog (289 , 132 , "Kreog", 6);
    // Federation :: Ship Independent (150 , 230 , "Greok");
    // WarpSystem :: QuantumReactor QR;
    // WarpSystem :: QuantumReactor QR2;
    // WarpSystem :: Core core (&QR);
    // WarpSystem :: Core core2 (&QR2);
    // UssKreog.setupCore(&core);
    // UssKreog.checkCore();
    // Independent.setupCore(&core2);
    // Independent.checkCore();
    // QR.setStability( false );
    // QR2.setStability( false );
    // UssKreog.checkCore();
    // Independent.checkCore();

    Federation :: Starfleet :: Ship UssKreog (289 , 132 , "Kreog", 6);
    Federation :: Starfleet :: Ship UssEntreprise;
    Federation :: Starfleet :: Captain James ("James T. Kirk") ;
    Federation :: Starfleet :: Ensign Ensign ("Pavel Chekov") ;
    WarpSystem :: QuantumReactor QR ;
    WarpSystem :: QuantumReactor QR2 ;
    std::cout << "Captain " << James.getName() << std::endl;
    QR.setStability(false);
    WarpSystem :: Core core (& QR ) ;
    WarpSystem :: Core core2 (& QR2 ) ;
    UssKreog.setupCore(&core);
    UssKreog.checkCore();
    UssKreog.promote (&James);
    Borg::Ship Cube;
    Borg::Ship Toto(20, 3);
    Cube.setupCore (&core2) ;
    Cube.checkCore () ;
    Toto.setupCore(&core2);
    Toto.checkCore();
    return 0;
}