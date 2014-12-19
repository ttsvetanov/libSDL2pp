/*
  libSDL2pp - C++11 bindings/wrapper for SDL2
  Copyright (C) 2013-2014 Dmitry Marakasov <amdmi3@amdmi3.ru>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SDL2PP_EXCEPTION_HH
#define SDL2PP_EXCEPTION_HH

#include <exception>

namespace SDL2pp {

////////////////////////////////////////////////////////////
/// \brief %Exception object representing SDL2 error
///
/// \ingroup general
///
/// \headerfile SDL2pp/Exception.hh
///
/// Internally, libSDL2pp checks return value of each SDL2
/// function it calls which may fail. If the function fails,
/// SDL2pp::Exception is thrown, and SDL2 error which expains
/// cause of function failure is stored in the exception and
/// may be extracted later.
///
/// what() usually contains a name of SDL2 function which failed,
/// e.g. "SDL_Init() failed"
///
/// Usage example:
/// \code
/// {
///     try {
///         SDL2pp::SDL sdl(SDL_INIT_VIDEO);
///     } catch (SDL2pp::Exception& e) {
///         std::cerr << "Fatal error:"
///                   << e.what()         // "SDL_Init failed"
///                   << ", SDL error: "
///                   << e.GetSDLError()  // "x11 not available"
///                   << std::endl;
///     }
/// }
/// \endcode
///
////////////////////////////////////////////////////////////
class Exception : public std::exception {
private:
	const char* what_;      ///< User-specified message
	const char* sdl_error_; ///< SDL error string

public:
	////////////////////////////////////////////////////////////
	/// \brief Construct exception, storing result of SDL_GetError
	///
	/// \param what User-specified explanatory string
	///
	////////////////////////////////////////////////////////////
	Exception(const char* what = "");


	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	////////////////////////////////////////////////////////////
	virtual ~Exception() noexcept;

	////////////////////////////////////////////////////////////
	/// \brief Get explanatory string
	///
	/// \returns Explanatory tring stored in the exception object
	///
	////////////////////////////////////////////////////////////
	const char* what() const noexcept;

	////////////////////////////////////////////////////////////
	/// \brief Get SDL2 error text
	///
	/// \returns Stored result of SDL_GetError()
	///
	/// \see http://wiki.libsdl.org/SDL_GetError
	///
	////////////////////////////////////////////////////////////
	const char* GetSDLError() const noexcept;
};

}

#endif
