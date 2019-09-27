/************************************************************************
**
**  Copyright (C) 2019  Kevin B. Hendricks, Stratford, Ontario, Canada
**
**  This file is part of Sigil.
**
**  Sigil is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Sigil is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Sigil.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/

#include <QString>
#include <QStringList>
#include <QHash>
#include "sigil_constants.h"
#include "Misc/MediaTypes.h"

const QStringList IMAGE_EXTENSIONS     = QStringList() << "jpg"   << "jpeg" << "png" << "gif"  << "tif"  << "tiff"  << "bm"
                                                       << "bmp";
const QStringList SVG_EXTENSIONS       = QStringList() << "svg";
const QStringList SMIL_EXTENSIONS      = QStringList() << "smil";
const QStringList JPG_EXTENSIONS       = QStringList() << "jpg"   << "jpeg";
const QStringList TIFF_EXTENSIONS      = QStringList() << "tif"   << "tiff";
const QStringList MISC_TEXT_EXTENSIONS = QStringList() << "txt"   << "js";
const QStringList MISC_XML_EXTENSIONS  = QStringList() << "smil"  << "xpgt" << "pls";
const QStringList FONT_EXTENSIONS      = QStringList() << "ttf"   << "ttc"  << "otf" << "woff" << "woff2";
const QStringList TEXT_EXTENSIONS      = QStringList() << "xhtml" << "html" << "htm";
const QStringList STYLE_EXTENSIONS     = QStringList() << "css";
const QStringList AUDIO_EXTENSIONS     = QStringList() << "aac"   << "m4a"  << "mp3" << "mpeg" << "mpg" << "oga" << "ogg";
const QStringList VIDEO_EXTENSIONS     = QStringList() << "m4v"   << "mp4"  << "mov" << "ogv"  << "webm" << "vtt" << "ttml";
const QStringList IMAGE_MIMEYPES       = QStringList() << "image/gif" << "image/jpeg" << "image/png";
const QStringList SVG_MIMETYPES        = QStringList() << "image/svg+xml";
const QStringList TEXT_MIMETYPES       = QStringList() << "application/xhtml+xml" << "application/x-dtbook+xml";
const QStringList STYLE_MIMETYPES      = QStringList() << "text/css";
const QStringList FONT_MIMETYPES       = QStringList() << "application/x-font-ttf" << "application/x-font-opentype" 
						       << "application/vnd.ms-opentype" << "application/font-woff" 
                                                       << "application/font-sfnt" << "font/woff2";
const QStringList AUDIO_MIMETYPES      = QStringList() << "audio/mpeg" << "audio/mp3" << "audio/ogg" << "audio/mp4";
const QStringList VIDEO_MIMETYPES      = QStringList() << "video/mp4" << "video/ogg" << "video/webm" 
                                                       << "text/vtt" << "application/ttml+xml";
const QStringList MISC_XML_MIMETYPES   = QStringList() << "application/oebps-page-map+xml" <<  "application/smil+xml" 
                                                       << "application/adobe-page-template+xml" 
						       << "application/vnd.adobe-page-template+xml" << "application/pls+xml";


MediaTypes *MediaTypes::m_instance = 0;

MediaTypes *MediaTypes::instance()
{
    if (m_instance == 0) {
        m_instance = new MediaTypes();
    }

    return m_instance;
}


QString MediaTypes::GetMediaTypeFromExtension(const QString &extension, const QString &fallback)
{
    return m_ExtToMType.value(extension, fallback);
}

QString MediaTypes::GetGroupFromMediaType(const QString &media_type, const QString &fallback)
{
    return m_MTypeToGroup.value(media_type, fallback);
}

QString MediaTypes::GetResourceDescFromMediaType(const QString &media_type, const QString &fallback)
{
    return m_MTypeToRDesc.value(media_type, fallback);
}


MediaTypes::MediaTypes()
{
    SetExtToMTypeMap();
    SetMTypeToGroupMap();
    SetMTypeToRDescMap();
}

void MediaTypes::SetExtToMTypeMap()
{
    if (!m_ExtToMType.isEmpty()) {
        return;
    }
    m_ExtToMType[ "bm"    ] = "image/bmp";
    m_ExtToMType[ "bmp"   ] = "image/bmp";
    m_ExtToMType[ "css"   ] = "text/css";
    m_ExtToMType[ "epub"  ] = "application/epub+zip";
    m_ExtToMType[ "gif"   ] = "image/gif";
    m_ExtToMType[ "htm"   ] = "application/xhtml+xml";
    m_ExtToMType[ "html"  ] = "application/xhtml+xml";
    m_ExtToMType[ "jpeg"  ] = "image/jpeg";
    m_ExtToMType[ "jpg"   ] = "image/jpeg";
    m_ExtToMType[ "js"    ] = "application/javascript";
    m_ExtToMType[ "m4a"   ] = "audio/mp4";
    m_ExtToMType[ "m4v"   ] = "video/mp4";
    m_ExtToMType[ "mp3"   ] = "audio/mpeg";
    m_ExtToMType[ "mp4"   ] = "video/mp4";
    m_ExtToMType[ "ncx"   ] = "application/x-dtbncx+xml";
    m_ExtToMType[ "oga"   ] = "audio/ogg";
    m_ExtToMType[ "ogg"   ] = "audio/ogg";
    m_ExtToMType[ "ogv"   ] = "video/ogg";
    m_ExtToMType[ "opf"   ] = "application/oebps-package+xml";
    m_ExtToMType[ "otf"   ] = "application/vnd.ms-opentype";
    m_ExtToMType[ "pls"   ] = "application/pls+xml";
    m_ExtToMType[ "png"   ] = "image/png";
    m_ExtToMType[ "smil"  ] = "application/smil+xml";
    m_ExtToMType[ "svg"   ] = "image/svg+xml";
    m_ExtToMType[ "tif"   ] = "image/tiff";
    m_ExtToMType[ "tiff"  ] = "image/tiff";
    m_ExtToMType[ "ttc"   ] = "application/x-font-truetype-collection";
    m_ExtToMType[ "ttf"   ] = "application/x-font-ttf";
    m_ExtToMType[ "ttml"  ] = "application/ttml+xml";
    m_ExtToMType[ "txt"   ] = "text/plain";
    m_ExtToMType[ "vtt"   ] = "text/vtt";
    m_ExtToMType[ "webm"  ] = "video/webm";
    m_ExtToMType[ "woff"  ] = "application/font-woff";
    m_ExtToMType[ "woff2" ] = "font/woff2";
    m_ExtToMType[ "xhtml" ] = "application/xhtml+xml";
    m_ExtToMType[ "xml"   ] = "application/oebs-page-map+xml";
    m_ExtToMType[ "xpgt"  ] = "application/adobe-page-template+xml";
    // m_ExtToMType[ "js"   ] = "text/javascript";
    // m_ExtToMType[ "otf"  ] = "application/x-font-opentype";
    // m_ExtToMType[ "otf"  ] = "application/font-sfnt";
}


void MediaTypes::SetMTypeToGroupMap()
{
    if (!m_MTypeToGroup.isEmpty()) {
        return;
    }
    m_MTypeToGroup[ "image/jpeg"                              ] = "Images";
    m_MTypeToGroup[ "image/png"                               ] = "Images";
    m_MTypeToGroup[ "image/gif"                               ] = "Images";
    m_MTypeToGroup[ "image/svg+xml"                           ] = "Images";
    m_MTypeToGroup[ "image/bmp"                               ] = "Images";
    m_MTypeToGroup[ "image/tiff"                              ] = "Images";
    m_MTypeToGroup[ "application/xhtml+xml"                   ] = "Text";
    m_MTypeToGroup[ "application/x-dtbook+xml"                ] = "Text";
    m_MTypeToGroup[ "application/x-font-ttf"                  ] = "Fonts";
    m_MTypeToGroup[ "application/x-font-opentype"             ] = "Fonts";
    m_MTypeToGroup[ "application/vnd.ms-opentype"             ] = "Fonts";
    m_MTypeToGroup[ "application/font-sfnt"                   ] = "Fonts";
    m_MTypeToGroup[ "application/font-woff"                   ] = "Fonts";
    m_MTypeToGroup[ "application/font-sfnt"                   ] = "Fonts";
    m_MTypeToGroup[ "font/woff2"                              ] = "Fonts";
    m_MTypeToGroup[ "application/x-font-truetype-collection"  ] = "Fonts";
    m_MTypeToGroup[ "audio/mpeg"                              ] = "Audio";
    m_MTypeToGroup[ "audio/mp3"                               ] = "Audio";
    m_MTypeToGroup[ "audio/mp4"                               ] = "Audio";
    m_MTypeToGroup[ "audio/ogg"                               ] = "Audio";
    m_MTypeToGroup[ "video/mp4"                               ] = "Video";
    m_MTypeToGroup[ "video/ogg"                               ] = "Video";
    m_MTypeToGroup[ "video/webm"                              ] = "Video";
    m_MTypeToGroup[ "text/vtt"                                ] = "Video";
    m_MTypeToGroup[ "application/ttml+xml"                    ] = "Video";
    m_MTypeToGroup[ "text/css"                                ] = "Styles";
    m_MTypeToGroup[ "application/x-dtbncx+xml"                ] = "ncx";
    m_MTypeToGroup[ "application/oebps-package+xml"           ] = "opf";
    m_MTypeToGroup[ "application/oebs-page-map+xml"           ] = "Misc";
    m_MTypeToGroup[ "application/smil+xml"                    ] = "Misc";
    m_MTypeToGroup[ "application/adobe-page-template+xml"     ] = "Misc";
    m_MTypeToGroup[ "application/vnd.adobe-page-template+xml" ] = "Misc";
    m_MTypeToGroup[ "text/javascript"                         ] = "Misc";
    m_MTypeToGroup[ "application/javascript"                  ] = "Misc";
    m_MTypeToGroup[ "application/pls+xml"                     ] = "Misc";
    m_MTypeToGroup[ "text/plain"                              ] = "Misc";
}


void MediaTypes::SetMTypeToRDescMap()
{
    if (!m_MTypeToRDesc.isEmpty()) {
        return;
    }
    m_MTypeToRDesc[ "application/xhtml+xml"                   ] = "HTMLResource";
    m_MTypeToRDesc[ "application/x-dtbook+xml"                ] = "HTMLResource";
    m_MTypeToRDesc[ "text/css"                                ] = "CSSResource";
    m_MTypeToRDesc[ "application/oebps-package+xml"           ] = "OPFResource";
    m_MTypeToRDesc[ "application/x-dtbncx+xml"                ] = "NCXResource";
    m_MTypeToRDesc[ "image/jpeg"                              ] = "ImageResource";
    m_MTypeToRDesc[ "image/png"                               ] = "ImageResource";
    m_MTypeToRDesc[ "image/gif"                               ] = "ImageResource";
    m_MTypeToRDesc[ "image/bmp"                               ] = "ImageResource";
    m_MTypeToRDesc[ "image/tiff"                              ] = "ImageResource";
    m_MTypeToRDesc[ "image/svg+xml"                           ] = "SVGResource";
    m_MTypeToRDesc[ "application/x-font-ttf"                  ] = "FontResource";
    m_MTypeToRDesc[ "application/x-font-opentype"             ] = "FontResource";
    m_MTypeToRDesc[ "application/vnd.ms-opentype"             ] = "FontResource";
    m_MTypeToRDesc[ "application/font-sfnt"                   ] = "FontResource";
    m_MTypeToRDesc[ "application/font-woff"                   ] = "FontResource";
    m_MTypeToRDesc[ "application/font-sfnt"                   ] = "FontResource";
    m_MTypeToRDesc[ "font/woff2"                              ] = "FontResource";
    m_MTypeToRDesc[ "application/x-font-truetype-collection"  ] = "FontResource";
    m_MTypeToRDesc[ "audio/mpeg"                              ] = "AudioResource";
    m_MTypeToRDesc[ "audio/mp3"                               ] = "AudioResource";
    m_MTypeToRDesc[ "audio/mp4"                               ] = "AudioResource";
    m_MTypeToRDesc[ "audio/ogg"                               ] = "AudioResource";
    m_MTypeToRDesc[ "video/mp4"                               ] = "VideoResource";
    m_MTypeToRDesc[ "video/ogg"                               ] = "VideoResource";
    m_MTypeToRDesc[ "video/webm"                              ] = "VideoResource";
    m_MTypeToRDesc[ "text/vtt"                                ] = "VideoResource";
    m_MTypeToRDesc[ "application/ttml+xml"                    ] = "VideoResource";
    m_MTypeToRDesc[ "application/oebs-page-map+xml"           ] = "XMLResource";
    m_MTypeToRDesc[ "application/smil+xml"                    ] = "XMLResource";
    m_MTypeToRDesc[ "application/adobe-page-template+xml"     ] = "XMLResource";
    m_MTypeToRDesc[ "application/vnd.adobe-page-template+xml" ] = "XMLResource";
    m_MTypeToRDesc[ "application/pls+xml"                     ] = "XMLResource";
    m_MTypeToRDesc[ "text/javascript"                         ] = "MiscTextResource";
    m_MTypeToRDesc[ "application/javascript"                  ] = "MiscTextResource";
    m_MTypeToRDesc[ "text/plain"                              ] = "MiscTextResource";
}
