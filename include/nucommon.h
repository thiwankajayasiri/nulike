!*         -*- mode: fortran -*-
!*######################################################################*
!*                       i n c l u d e     f i l e                      *
!*######################################################################*

!************************************************************************
!***                           nuprep.h                               ***
!***         this piece of code is needed as a separate file          ***
!----------------------------------------------------------------------c
!  author: Pat Scott (patscott@physics.mcgill.ca), June 12, 2014

      integer max_nPrecompE,max_nSensBins,max_nBinsBGAng,max_nBinsBGE,max_nEvents,max_nHistograms,max_ncols
      parameter(max_nPrecompE   = 1000) !Maximum number partial likelihoods per event
      parameter(max_nSensBins   = 50)   !Maximum number of bins in the effective area or volume
      parameter(max_nBinsBGAng  = 180)  !Maximum number of angular bins in the background
      parameter(max_nBinsBGE    = 20)   !Maximum number of spectral bins in the background
      parameter(max_nEvents     = 2000) !Maximum number of events for any analysis
      parameter(max_nHistograms = 20)   !Max number of energy windows to give the energy dispersion in
      parameter(max_ncols       = 80)   !Max number of columns (entries) in a single energy-window histogram

      integer angular, enrgyest, events, lun
      parameter(angular = 1, enrgyest = 2, events = 3, lun = 20)

      integer analysis, nAnalyses

      real*8 pi
      parameter (pi=3.141592653589793238d0)

      character (len=15) hstring(3)
      parameter(hstring = (/'####--Angular--',
     &                      '####--Nchan--  ',
     &                      '####--Nevents--'/))

      common /nu_comm/ analysis, nAnalyses
      save /nu_comm/

      ! This parameter will be initialized in a block data routine
      ! (see flagblocks.f).  The external line below
      ! ensures the block data routine is loaded at compile time.
      logical credits_rolled
      common /nulike_credit_flag/ credits_rolled
      save /nulike_credit_flag/
      external nulike_credit_flagblock

!*************************** end of nulike.h *****************************