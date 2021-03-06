/*---------------------------------------------------------------------------*\
                pdfFoam: General Purpose PDF Solution Algorithm
                   for Reactive Flow Simulations in OpenFOAM

 Copyright (C) 2012 Michael Wild, Heng Xiao, Patrick Jenny,
                    Institute of Fluid Dynamics, ETH Zurich
-------------------------------------------------------------------------------
License
    This file is part of pdfFoam.

    pdfFoam is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) version 3 of the same License.

    pdfFoam is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with pdfFoam.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::mcParticleLocalTimeStepping

Description
    Particle-based local time-stepping

    Every particle gets an individual local timestep based on its Courant
    number and a global CFL condition: eta = CFL / (deltaT*Co)

SourceFiles
    mcParticleLocalTimeStepping.C

Author
    Michael Wild

\*---------------------------------------------------------------------------*/

#ifndef mcParticleLocalTimeStepping_H
#define mcParticleLocalTimeStepping_H

#include "mcLocalTimeStepping.H"

#include "volFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                 Class mcParticleLocalTimeStepping Declaration
\*---------------------------------------------------------------------------*/

class mcParticleLocalTimeStepping :
    public mcLocalTimeStepping
{
    // Private Data

        //- The upper cut-off for the local time-stepping parameter
        scalar upperBound_;

    // Private Member Functions

        // Disallow default bitwise copy construct and assignment
        mcParticleLocalTimeStepping(const mcParticleLocalTimeStepping&);
        void operator=(const mcParticleLocalTimeStepping&);

public:

    //- Runtime type information
    TypeName("mcParticleLocalTimeStepping");

    // Constructors

        //- Construct from components
        mcParticleLocalTimeStepping
        (
            mcParticleCloud& cloud,
            const objectRegistry& db,
            const word& subDictName
        );

    // Member Functions

        //- Update/prepare internal data
        virtual void updateInternals();

        //- Apply the position correction to a single particle
        virtual void correct(mcParticle& p);
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
