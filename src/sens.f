***********************************************************************
*** nulike_sens provides the interpolated effective area/volume of the 
*** IceCube experiment to either neutrinos or anti-neutrinos.
***
*** Input:	log10E	        log(neutrino energy/GeV)
*** 		ptype	= 1	neutrinos
***			= 2	anti-neutrinos
*** Output:                     effective area or volume (m^2 or m^3)
***       
*** Author: Pat Scott (patscott@physics.mcgill.ca)
*** Date: Apr 24, 2011
*** Modified: Jun 6 2014
***********************************************************************

      real*8 function nulike_sens(log10E, ptype)

      implicit none
      include 'nulike.h'

      real*8 log10E
      integer ptype, IER
      
      !Choose relevant species
      if (ptype .eq. 1) then

        !neutrinos
        call TSVAL1(nSensBins(analysis),sens_logEcentres(:,analysis),
     &   sens_nu(:,analysis),sens_nuderivs(:,analysis),
     &   sens_nusigma(:,analysis),0,1,log10E,nulike_sens,IER)

      else if (ptype .eq. 2) then

        !anti-neutrinos
        call TSVAL1(nSensBins(analysis),sens_logEcentres(:,analysis),
     &   sens_nubar(:,analysis),sens_nubarderivs(:,analysis),
     &   sens_nubarsigma,0,1,log10E,nulike_sens,IER)

      else

        write(*,*) 'Error in nulike_sens:'
        write(*,*) 'unrecognised ptype; quitting...'

      endif

      if (IER .lt. 0) then
        write(*,*) 'TSVAL1 error from effective area'
        write(*,*) 'in nulike_sens, code:', IER
        stop
      endif

      end function nulike_sens