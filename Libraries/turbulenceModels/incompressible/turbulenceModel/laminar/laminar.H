/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.0
    \\  /    A nd           | Web:         http://www.foam-extend.org
     \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::incompressible::laminar

Description
    Turbulence model for laminar incompressible flow.

SourceFiles
    laminar.C

\*---------------------------------------------------------------------------*/

#ifndef laminar_H
#define laminar_H

#include "turbulenceModelNew.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace incompressible
{

/*---------------------------------------------------------------------------*\
                           Class laminar Declaration
\*---------------------------------------------------------------------------*/

class laminar
:
    public turbulenceModelNew

{

public:

    //- Runtime type information
    TypeName("laminar");

    // Constructors

        //- Construct from components
        laminar
        (
            const volVectorField& U,
            const surfaceScalarField& phi,
            transportModelNew& transport
        );


    // Selectors

        //- Return a reference to the selected turbulence model
        static autoPtr<laminar> New
        (
            const volVectorField& U,
            const surfaceScalarField& phi,
            transportModelNew& lamTransportModel
        );


    //- Destructor
    virtual ~laminar()
    {}


    // Member Functions

        //- Return the turbulence viscosity, i.e. 0 for laminar flow
        virtual tmp<volScalarField> nut() const;

        //- Return the effective viscosity, i.e. the laminar viscosity
        virtual tmp<volScalarField> nuEff() const;

        //- Return the turbulence kinetic energy, i.e. 0 for laminar flow
        virtual tmp<volScalarField> k() const;

        //- Return the turbulence kinetic energy dissipation rate,
        //  i.e. 0 for laminar flow
        virtual tmp<volScalarField> epsilon() const;

        //- Return the Reynolds stress tensor, i.e. 0 for laminar flow
        virtual tmp<volSymmTensorField> R() const;

        //- Return the effective stress tensor, i.e. the laminar stress
        virtual tmp<volSymmTensorField> devReff() const;

        //- Return the source term for the momentum equation
        virtual tmp<fvVectorMatrix> divDevReff() const;

        //- Correct the laminar viscosity
        virtual void correct();

        //- Read turbulenceProperties dictionary
        virtual bool read();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace incompressible
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
