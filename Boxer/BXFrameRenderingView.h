/* 
 Boxer is copyright 2009 Alun Bestor and contributors.
 Boxer is released under the GNU General Public License 2.0. A full copy of this license can be
 found in this XCode project at Resources/English.lproj/GNU General Public License.txt, or read
 online at [http://www.gnu.org/licenses/gpl-2.0.txt].
 */


//BXFrameRenderingView is a protocol for views that perform drawing of BXEmulator frames.
//It provides a consistent interface for BXSessionWindowController to communicate with
//different alternative view implementations.

#import <Cocoa/Cocoa.h>

@class BXFrameBuffer;

@protocol BXFrameRenderingView
@property (assign) BOOL managesAspectRatio;

- (void) updateWithFrame: (BXFrameBuffer *)frame;

@end