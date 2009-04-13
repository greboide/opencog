/*
 * opencog/embodiment/AGISimSim/proxy/DOMPrintErrorHandler.h
 *
 * Copyright (C) 2002-2007 Novamente LLC
 * All Rights Reserved
 *
 * Written by TO_COMPLETE
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#ifndef DOM_PRINT_ERROR_HANDLER_HPP
#define DOM_PRINT_ERROR_HANDLER_HPP

#include <xercesc/dom/DOMErrorHandler.hpp>

XERCES_CPP_NAMESPACE_USE

class DOMPrintErrorHandler : public DOMErrorHandler
{
public:

    DOMPrintErrorHandler() {};
    ~DOMPrintErrorHandler() {};

    /** @name The error handler interface */
    bool handleError(const DOMError& domError);
    void resetErrors() {};

private :
    /* Unimplemented constructors and operators */
    DOMPrintErrorHandler(const DOMErrorHandler&);
    void operator=(const DOMErrorHandler&);

};

#endif