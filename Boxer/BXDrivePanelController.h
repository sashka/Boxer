/* 
 Boxer is copyright 2011 Alun Bestor and contributors.
 Boxer is released under the GNU General Public License 2.0. A full copy of this license can be
 found in this XCode project at Resources/English.lproj/BoxerHelp/pages/legalese.html, or read
 online at [http://www.gnu.org/licenses/gpl-2.0.txt].
 */


//BXDrivePanelController manages the Drives panel of the Inspector window.

#import <Cocoa/Cocoa.h>
#import "BXOperationDelegate.h"

@class BXDriveList;
@class BXDrive;
@interface BXDrivePanelController : NSViewController <BXOperationDelegate>
{
	IBOutlet NSSegmentedControl *driveControls;
	IBOutlet NSMenu *driveActionsMenu;
	IBOutlet BXDriveList *driveList;
    
    NSIndexSet *selectedDriveIndexes;
}

#pragma mark -
#pragma mark Properties

@property (retain, nonatomic) BXDriveList *driveList;
@property (retain, nonatomic) NSSegmentedControl *driveControls;
@property (retain, nonatomic) NSMenu *driveActionsMenu;

//The list of drives to display for the current session.
//This is pre-filtered with driveFilterPredicate.
@property (readonly, nonatomic) NSArray *drives;

//The currently-selected drives, formatted for our array controller.
@property (retain, nonatomic) NSIndexSet *selectedDriveIndexes;

//How our array controller should filter our drives.
@property (readonly, nonatomic) NSPredicate *driveFilterPredicate;

//The currently-selected drives, formatted for our personal use.
@property (readonly, nonatomic) NSArray *selectedDrives;


#pragma mark -
#pragma mark Interface Actions

- (IBAction) interactWithDriveOptions: (NSSegmentedControl *)sender;

//Reveal the selected drives each in a new Finder window.
- (IBAction) revealSelectedDrivesInFinder: (id)sender;

//Change to the first selected drive in DOS. This action is disabled if a process is running.
- (IBAction) openSelectedDrivesInDOS: (id)sender; 

//Unmount the selected drives from DOS, while leaving them in the drive list.
- (IBAction) unmountSelectedDrives: (id)sender;

//Unmount the selected drives from DOS, and remove them from the drive list altogether.
- (IBAction) removeSelectedDrives: (id)sender;

//Import the selected drives into the gamebox.
- (IBAction) importSelectedDrives: (id)sender;

//Cancel the import operation for the drive represented by the sender.
- (IBAction) cancelImportForDrive: (id)sender;

//Cancel the import operations for all currently selected drives.
- (IBAction) cancelImportsForSelectedDrives: (id)sender;

//Display the mount panel.
- (IBAction) showMountPanel: (id)sender;

//Re-syncs the status and actions of the button bar, whenever
//the selection changes or drives get mounted/unmounted.
- (void) syncButtonStates;

#pragma mark -
#pragma mark Drag-dropping

//Handle drag-dropping of files and folders to mount as drives.
- (NSDragOperation) draggingEntered: (id <NSDraggingInfo>)sender;
- (BOOL) performDragOperation: (id <NSDraggingInfo>)sender;

- (BOOL) collectionView: (NSCollectionView *)collectionView
    writeItemsAtIndexes: (NSIndexSet *)indexes
           toPasteboard: (NSPasteboard *)pasteboard;

@end
